const express = require("express");
const cors = require("cors");
const bodyparser = require("body-parser");
const path = require("path");
const employeeRoutes = require("./routes/route.js")


const app = express();


app.use(cors());
app.use(bodyparser.json());
app.use(bodyparser.urlencoded({extended:true}));


app.set("view engine",'ejs');
app.set("views",path.join(__dirname,"views"));


app.get("/",(req,res)=>{
    res.send("hello developer");
})



app.use("/route",employeeRoutes);


app.listen(3000,()=>{
    console.log("Listening on port 3000");
})
