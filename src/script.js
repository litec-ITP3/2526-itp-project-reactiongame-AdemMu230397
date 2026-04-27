let port;
let writer;
let reader;

async function connect() {

port = await navigator.serial.requestPort();
await port.open({ baudRate: 9600 });

writer = port.writable.getWriter();
reader = port.readable.getReader();

document.getElementById("status").innerText = "CONNECTED";

readSerial();
}

async function startGame() {

document.getElementById("winner").innerText = "";
document.getElementById("countdown").innerText = "3";
await sleep(1000);

document.getElementById("countdown").innerText = "2";
await sleep(1000);

document.getElementById("countdown").innerText = "1";
await sleep(1000);

document.getElementById("countdown").innerText = "";
await sleep(Math.random()*3000+1000);

document.getElementById("countdown").innerText = "GO!";

await writer.write(new TextEncoder().encode("START\n"));
}

async function readSerial(){

while(true){
const { value, done } = await reader.read();

if(done) break;

let text = new TextDecoder().decode(value).trim();

if(text=="P1"){
document.getElementById("winner").innerText="SPIELER 1 GEWINNT!";
}

if(text=="P2"){
document.getElementById("winner").innerText="SPIELER 2 GEWINNT!";
}
}
}

function sleep(ms){
return new Promise(r => setTimeout(r, ms));
}