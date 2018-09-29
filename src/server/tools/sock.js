import friendsData from "./friends"

// 注册
export async function login(ctx, users, msg) {
    let state = 0
    if (users.in_array({ userid: msg.userid, meet: ctx })) {
        state = 1
    }
    //注册回复协议：0表示成功 1表示失败
    let loginData = {
        cmd: 100001,
        success: 1,
        data:[{
            userid:100001,
            nickname: 'leo',
            image:1
        }],
        error:{
            cmd: 0,
            message: ""
        }
    }
    console.log(loginData)
    ctx.websocket.send(JSON.stringify(loginData));
}

// 好友列表
export async function friends(ctx, users, msg) {
    ctx.websocket.send(JSON.stringify(friendsData));
}

// 消息传递
export async function messagePassing(ctx, users, msg) {
    let other_userid = msg.otherid
    let other_user = users.other_array(other_userid)
    if (other_user.userid) {
        msg.cmd = 100004
        msg.success = 1;
        msg.error = {
            cmd: 0,
            message: ""
        }
        other_user.meet.websocket.send(JSON.stringify(msg));
    }
}

