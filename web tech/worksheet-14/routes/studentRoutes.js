const express = require("express");
const router = express.Router();

const {
    getStudents,
    showAddForm,
    addStudent,
    showEditForm,
    updateStudent,
    deleteStudent
} = require("../controllers/studentController");

router.get("/", getStudents);
router.get("/add", showAddForm);
router.post("/add", addStudent);
router.get("/edit/:id", showEditForm);
router.post("/update/:id", updateStudent);
router.post("/delete/:id", deleteStudent);

module.exports = router;
