const fs = require("node:fs");
const path = require("path");


const postEmployee = (req,res)=>{
    try {
        const {name,date,time_in,time_out} = req.body;
        const data = `${name}, ${date}, ${time_in}, ${time_out}\n`;
        if(!fs.existsSync(path.join(__dirname,"../log/employeeLog.txt"))){
            fs.writeFileSync(path.join(__dirname,"../log/employeeLog.txt"),data);
        }else{
            fs.appendFileSync(path.join(__dirname,"../log/employeeLog.txt"),data);
        }
        res.redirect("/route/form");
    } catch (error) {
        console.log(error.message);
    }
}


const loadForm = async (req,res)=>{
    try {
        await res.render("employee");
    } catch (error) {
        console.log(error);
    }
}


module.exports = {postEmployee, loadForm};

