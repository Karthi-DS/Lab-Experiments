const mongoose = require("mongoose");



const studentSchema = new mongoose.Schema({
    rollNo:{
        type:String,
        required:true
    },
    name:{
        type:String,
        required:true
    },
    guardian_p_no:{
        type:Number,
        required:true
    },
    skills:{
        type:[String],
    }
})

const studentModel = new mongoose.model("students",studentSchema);


module.exports = studentModel;