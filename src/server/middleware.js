import Koa from 'koa2'
import WebSocket from 'koa-websocket'
import convert from 'koa-convert'
import json from 'koa-json'
import Bodyparser from 'koa-bodyparser'
import logger from 'koa-logger'
import path from 'path'
// import favicon from 'koa-favicon'
import cors from 'koa-cors'

const app = WebSocket(new Koa())


// middlewares
app.use(convert(cors()))
app.use(convert(Bodyparser()))
app.use(convert(json()))
app.use(convert(logger()))
app.use(convert(require('koa-static')(path.join(__dirname, './dist'))))
    // app.use(favicon(path.join(__dirname, '../favicon.ico')))
    // logger
app.use(async(ctx, next) => {
    console.log(ctx.query)
    const start = new Date()
    await next()
    const ms = new Date() - start
    console.log(`${ctx.method} ${ctx.url} - ${ms}ms`)
})

// response
app.on('error', (err, ctx) => {
    logger.error('server error', err, ctx)
})

export default app