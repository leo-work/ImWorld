import Router from 'koa-router'
import { user } from '../controllers/index.js'
const router = new Router({
    prefix: '/user'
})


router.get('/login', user.login)

router.get('/register', user.register)

router.get('/list', user.user_list)

export default router