import { createClient } from 'then-redis'

const clientRedis = createClient({
  host: '127.0.0.1',
  port: 6379
})

export default {clientRedis}
