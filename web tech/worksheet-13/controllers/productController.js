const fs = require("node:fs");
const path = require("path");




const writeProduct = (req,res)=>{
    try {
        const {id, name, price, stock } = req.body;
        const data = `${id},${name},${price},${stock}\n`;
        if(!fs.existsSync(path.join(__dirname,"../log/productLog.csv"))){
            fs.writeFileSync(path.join(__dirname,"../log/productLog.csv"),data);
            console.log("Written product into products");
        }else{
            fs.appendFileSync(path.join(__dirname,"../log/productLog.csv"),data);
        }
        res.redirect("/route/productform")
    } catch (error) {
        console.log(error.message);
        res.send(500).json({error});
    }
}

const parseProducts =()=>{
    const data = fs.readFileSync(path.join(__dirname,"../log/productLog.csv"),"utf-8").toString();
    const products  = data.split("\n").filter(line => line.trim() !== "").map(d=>{
    const p = d.split(",")
            return {
                id:p[0],
                name:p[1],
                price:p[2],
                stock:p[3]
            }
    });
    return products;
}

const renderProducts = (req,res)=>{
    try {
        const products = parseProducts();
        res.render("displayProduct",{products:products});
    } catch (error) {
        console.log(error);
        res.status(500).json({error});
    }
}

const loadProductForm = async(req,res)=>{
    try {
        await res.render("product",{product:null});
    } catch (error) {
        console.log(error);
        res.status(500).json({error});
    }
}

const getProduct = (req,res)=>{
    try {
        const id = req.params.id;
        const products = parseProducts();
        const product = products.find(p=>p.id==id);
        res.render("product",{product:product});
    } catch (error) {
        res.status(500).json({error});
    }
}

const updateProduct = (req,res)=>{
    try {
        const {id,name, price, stock } = req.body;
        const products = parseProducts();
        const newProducts = products.map(p=>{
            if(p.id == id){
                return{...p,name:name,price:price,stock:stock}
            }
            return p;
        });
        const data = newProducts.reduce(
            (r,d)=> r+`${d.id},${d.name},${d.price},${d.stock}`,'');
        console.log(data);
        fs.writeFileSync(path.join(__dirname,"../log/productLog.csv"),data);
        res.redirect("/route/getProduct");
    } catch (error) {
        res.status(500).json({error});
    }
}

const deleteProduct = (req,res)=>{
    try {
        const id = req.params.id;
        const products = parseProducts();
        const newProducts = products.filter(p=>p.id!=id);
        const data = newProducts.reduce(
            (r,d)=> r+`${d.id},${d.name},${d.price},${d.stock}`,'');
        fs.writeFileSync(path.join(__dirname,"../log/productLog.csv"),data);
        res.redirect("/route/getProduct");
    } catch (error) {
        res.status(500).json({error});
    }
}


module.exports = {writeProduct,renderProducts,loadProductForm,deleteProduct,getProduct,updateProduct};
