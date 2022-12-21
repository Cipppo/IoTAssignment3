function updateClock() {
    // Ivo's content to create the date.
    const d = new Date();
    let ore = d.getHours();
    let minuti = d.getMinutes();
    let secondi = d.getSeconds();
    data.innerHTML = ore + ":" + minuti + ":" + secondi;
}




let accendi = document.getElementById('Accendi');
let spegni = document.getElementById('Spegni');
let invia = document.getElementById('Invia');
let slider = document.getElementById('Slider');
let data = document.getElementById('Data')

spegni.addEventListener("click", function(e){
    console.log("a");
    spegni.className = "btn btn-success";
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
    val = slider.value;
    axios.post('http://127.0.0.1:5555/api/slider', {
        "value": "10"
    });
})



setInterval(updateClock, 1000);