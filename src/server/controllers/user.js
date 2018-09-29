// 登录
export async function login(ctx, next) {
    let userinfo = ctx.request.body
    ctx.body = {
        code: 202
    }
}

// 注册
export async function register(ctx, next) {
    let userinfo = ctx.request.body
    ctx.body = {
        code: 201
    }
}


// 注册
export async function user_list(ctx, next) {
    let userlist = []
    let users = ctx.tools.users
    for (let value of users) {
        userlist.push(value.userid)
    }
    ctx.body = {
        code: 201,
        all: userlist
    }
}