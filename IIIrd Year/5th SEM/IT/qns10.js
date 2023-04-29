




const http = require('http')
const hostname = '127.0.0.1'
const port = 10000
const server = http.createServer((req, res) => {
    res.statusCode = 200
    // res.setHeader('content-type', 'Hii.html')
    // res.write("Hello world this is my node js")
    res.end('Hello world, this is node js')
}).listen(port, () => {
    console.log(`Server is running on http://${hostname}:${port}`);
})