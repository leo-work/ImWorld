import app from './middleware'
import routerList from './routes/index'
import daos from './daos/index'
import { socktools } from './tools/index'
// import {sql} from './lib/mysql/index'
// import {clientRedis} from './lib/redis/index'


Array.prototype.in_array = function(user) {　
    for (var i = 0; i < this.length; i++) {　　
        if (this[i].userid == user.userid) {　　
            this[i].meet = user.meet
            return true
        }
    }
    if (user.userid) {
        this.push(user)
    }
    return false
}

Array.prototype.other_array = function(userid) {　
    for (var i = 0; i < this.length; i++) {　　
        if (this[i].userid === userid) {　　
            return this[i]
        }
    }
    return {}
}

Array.prototype.remove_array = function(ctx) {　　
    let userid = 0
    for (var i = 0; i < this.length; i++) {　
        if (this[i].meet === ctx) {　　
            userid = this[i].userid
            this.splice(i, 1);
            return userid
        }
    }
    return userid
}

let users = new Array()

// 配置数据库和redis，模块
app.use(async(ctx, next) => {
    ctx.tools = { users }
    ctx.daos = daos
    await next()
})

app.ws.use((ctx, next) => {
    /* 每打开一个连接就往 上线文数组中 添加一个上下文 */
    ctx.websocket.on("message", (message) => {
        let msg = JSON.parse(message)
        let cmd = msg.cmd
        switch (cmd) {
            case 100001:
                console.log("login message come!" + msg.cmd)
                socktools.login(ctx, users, msg)
                break
            case 100002:
                console.log("friends message come!" + msg.cmd)
                socktools.friends(ctx, users, msg)
                break
            case 100003:
                console.log("messagePassing message come!" + msg.cmd)
                socktools.messagePassing(ctx, users, msg)
                break
            default:
                break
        }
    });
    ctx.websocket.on("close", (message) => {
        /* 连接关闭时, 清理 上下文数组, 防止报错 */
        let userid = users.remove_array(ctx)
        console.log(userid + " go ro bed!")
    });
})


// 遍历所有的路由
routerList.map((routerValue) => {
    app.use(routerValue.routes(), routerValue.allowedMethods())
})

export default app
