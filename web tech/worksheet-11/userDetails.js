const data = localStorage.getItem("userData");
const btn = document.getElementById("submit")
const form = document.querySelector('form');

if(data){
    btn.value = 'Edit & Save';
}else{
    btn.value = 'Add User'
}

document.addEventListener('DOMContentLoaded',()=>{
    if(data){
        const userData = JSON.parse(data);
        document.querySelector("input[name='name']").value = userData.name;
        document.querySelector("input[name='email']").value = userData.email;
        document.querySelector("select").value = userData.role;
    }
})

form.addEventListener('submit',(e)=>{
    e.preventDefault();
    const formData = new FormData(form);
    const formValues = Object.fromEntries(formData.entries());
    localStorage.setItem('userData',JSON.stringify(formValues));

})