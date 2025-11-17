require("dotenv").config();
const express = require("express");
const cors = require("cors");
const connectDB = require("./config/db");
const studentRoutes = require("./routes/studentRoutes");
const path = require("path");

const port = process.env.PORT||5000;
const app = express();

//middlewares - essentials

app.use(cors());
app.use(express.json());
app.use(express.urlencoded({extended:true}));

app.set("view engine","ejs");
app.set("views",path.join(__dirname,"views"));


//connect DB
connectDB();

//middlewares - routes

app.use("/students",studentRoutes);

app.get("/",(req,res)=>{
    res.send("hello developer");
})

app.listen(port,()=>{
    console.log(`port listening on ${port}`)
})