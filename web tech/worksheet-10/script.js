// === Form Validation Setup ===

// Validation rules and messages (config-driven)
const validationRules = {
  name: {
    regex: /^[A-Za-z ]+$/,
    message: "Name should only contain alphabets and spaces",
  },
  email: {
    regex: /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.(com|edu|in)$/,
    message: "Enter a valid email ending with .com, .edu or .in",
  },
  password: {
    regex: /^(?=.*[0-9]).{6,}$/,
    message: "Password must be at least 6 chars and contain one number",
  },
  mobile: {
    regex: /^\d{10}$/,
    message: "Mobile number must be exactly 10 digits",
  },
};

const validationState = {};
Object.keys(validationRules).forEach((id) => (validationState[id] = false));

Object.keys(validationRules).forEach((id) => {
  const input = document.getElementById(id);
  if (input) input.addEventListener("blur", (e) => validateField(e.target.id));
});

function validateField(id) {
  const { regex, message } = validationRules[id];
  const input = document.getElementById(id);
  const value = input.value.trim();
  const p = document.getElementById(id + "p");
  const span = document.getElementById(id + "Span");

  if (!regex.test(value)) {
    p.textContent = message;
    p.style.color = "red";
    span.textContent = "❌";
    validationState[id] = false;
  } else {
    p.textContent = "";
    span.textContent = "✔";
    span.style.color = "green";
    validationState[id] = true;
  }
}

function displayData() {
  const form = document.getElementById("surveyForm");
  const formData = new FormData(form);

  const name = formData.get("name");
  const email = formData.get("email");
  const mobile = formData.get("mobile");
  const dob = formData.get("dob");
  const rating = formData.get("rating") || "None";
  const interests = formData.getAll("interests").join(", ") || "None";

  alert(
    `Name: ${name}\nEmail: ${email}\nMobile: ${mobile}\nDOB: ${dob}\nRating: ${rating}\nInterests: ${interests}`
  );
}

function submitForm() {
  // Validate all before submit
  Object.keys(validationRules).forEach((id) => validateField(id));
  const allValid = Object.values(validationState).every((v) => v === true);

  if (!allValid) {
    alert("Please correct all errors before submitting.");
    return false;
  }

  const form = document.getElementById("surveyForm");
  const formData = new FormData(form);
  const name = formData.get("name");
  const email = formData.get("email");
  const rating = formData.get("rating") || "None";
  const interests = formData.getAll("interests");

  localStorage.setItem(
    "formData",
    JSON.stringify({ name, email, rating, interests })
  );

  return true;
}

document
  .getElementById("surveyForm")
  .addEventListener("reset", () => {
    document
      .querySelectorAll("span[id$='Span']")
      .forEach((span) => (span.textContent = ""));
    document
      .querySelectorAll("p[id$='p']")
      .forEach((p) => (p.textContent = ""));
    Object.keys(validationState).forEach((k) => (validationState[k] = false));
  });
