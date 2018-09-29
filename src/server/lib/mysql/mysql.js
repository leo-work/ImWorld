import mysql from 'promise-mysql'

let pool = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: '',
  database: 'blog',
  port: 3306,
  connectionLimit: 10
})

export async function getSqlData ({sqlQuery, arg}) {
  let data
  try {
    let conn = await pool.getConnection()
    data = await conn.query(sqlQuery, arg)
    await pool.releaseConnection(conn)
  } catch (err) {
    data = null
    console.log('err:', err)
  }
  return data
}




