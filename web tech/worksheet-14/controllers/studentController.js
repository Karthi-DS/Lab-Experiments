const studentModel = require("../models/studentModel");

const getStudents = async (req, res) => {
    try {
        const students = await studentModel.find();
        res.render("home", { data: students });
    } catch (error) {
        res.status(500).send(error.message);
    }
};

const showAddForm = (req, res) => {
    res.render("addStudent");
};

const addStudent = async (req, res) => {
    try {
        await studentModel.create(req.body);
        res.redirect("/students");
    } catch (error) {
        res.status(500).send(error.message);
    }
};

const showEditForm = async (req, res) => {
    try {
        const student = await studentModel.findById(req.params.id);
        res.render("editStudent", { student });
    } catch (error) {
        res.status(500).send(error.message);
    }
};

const updateStudent = async (req, res) => {
    try {
        await studentModel.findByIdAndUpdate(req.params.id, req.body);
        res.redirect("/students");
    } catch (error) {
        res.status(500).send(error.message);
    }
};

const deleteStudent = async (req, res) => {
    try {
        await studentModel.findByIdAndDelete(req.params.id);
        res.redirect("/students");
    } catch (error) {
        res.status(500).send(error.message);
    }
};

module.exports = {
    getStudents,
    showAddForm,
    addStudent,
    showEditForm,
    updateStudent,
    deleteStudent
};
