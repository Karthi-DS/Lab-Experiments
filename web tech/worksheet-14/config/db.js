const mongoose = require("mongoose");
const uri = process.env.MONGO_URI;

const connectDB = async()=>{
    try {
        await mongoose.connect(uri);
        console.log("DB is connected");
    } catch (error) {
        console.log(`Error: ${error.message}`);
    }
}

module.exports = connectDB;