const data = {
      "rollNo": "21",
      "name": "test kartheesvaran",
      "guardian_p_no": 808098098,
      "skills": [
        "frontend,backend"
      ],
    };

const fetchRes=async()=>{
    try {
        const res = await 
        fetch("http://localhost:5000/students/add",
            {
                method:"POST",
                body:JSON.stringify(data),
                headers:{
                    "Content-Type":"application/json"
                }
            }
        ).then(res=>res.json());
        console.log(res);
    } catch (error) {
        
    }
}

fetchRes();