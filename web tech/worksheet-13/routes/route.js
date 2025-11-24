const router = require("express").Router();
const {postEmployee, loadForm} = require("../controllers/employeeController.js");
const {writeProduct,renderProducts,loadProductForm,deleteProduct,getProduct,updateProduct} 
= require("../controllers/productController.js");


//employeeRoutes.js
router.post("/postEmployee",postEmployee);
router.get("/form",loadForm);


//productRoutes.js
router.get("/productform",loadProductForm)
router.post("/postProduct",writeProduct);
router.get("/getProduct",renderProducts);
router.get("/deleteProduct/:id",deleteProduct);
router.get("/editProduct/:id",getProduct);
router.post("/updateProduct",updateProduct);


module.exports = router;
