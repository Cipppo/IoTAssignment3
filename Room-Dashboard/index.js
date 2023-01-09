function updateClock() {
    // Ivo's content to create the date.
    const d = new Date();
    let ore = d.getHours();
    let minuti = d.getMinutes();
    let secondi = d.getSeconds();
    data.innerHTML = ore + ":" + minuti + ":" + secondi;
}

function updateDebug() {
    const res = axios.get('http://127.0.0.1:5555/api/debug');
    
}




let accendi = document.getElementById('Accendi');
let spegni = document.getElementById('Spegni');

let invia = document.getElementById('Invia');
let slider = document.getElementById('Slider');

let data = document.getElementById('Data');

let apriTutto = document.getElementById('ApriTutto');
let chiudiTutto = document.getElementById('ChiudiTutto');

let timeSet0 = document.getElementById('timeSet8');
let timeSet19 = document.getElementById('timeSet19');


spegni.addEventListener("click", function(e){
    console.log("a");
    spegni.className = "btn btn-danger";
    accendi.className = "btn btn-dark"; 
    axios.get('http://127.0.0.1:5555/api/led?LED=0');

})

accendi.addEventListener("click", function(e){
    console.log("b");
    accendi.className = "btn btn-success";
    spegni.className = "btn btn-dark";
    axios.get('http://127.0.0.1:5555/api/led?LED=1');
})

invia.addEventListener("click", function(e){
    let val = slider.value
    axios.post('http://127.0.0.1:5555/api/slider', {
        method: 'POST', 
        headers:{
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({
            value: val
        })
    })
    .then(data => console.log(data))
    .catch(error => console.error(error));
})



setInterval(updateClock, 1000);
setInterval(updateDebug, 500);