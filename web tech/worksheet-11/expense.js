const data = localStorage.getItem("userData");
const form = document.querySelector('form');
const expenseData = JSON.parse(localStorage.getItem("expenseData")&&localStorage.getItem("expenseData"))||[];


document.addEventListener("DOMContentLoaded", () => {
  if (data) {
    const disclaimer = document.querySelector(".disclaimer");
    disclaimer.style.display = "none";
  } else {
    console.log("No user data found. Hiding form.");
    const form = document.querySelector("form");
    if (form) form.style.display = "none";
  }
});

form.addEventListener('submit',(e)=>{
    e.preventDefault();
    const formData = new FormData(form);
    const formValues = Object.fromEntries(formData.entries());
    console.log(formValues);
    expenseData.push(formValues);
    localStorage.setItem("expenseData",JSON.stringify(expenseData));
})