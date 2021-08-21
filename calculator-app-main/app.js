const display=document.getElementById("dis");
const b=document.getElementById("bod")
const numbers=document.getElementsByClassName("number");
const res=document.getElementById("reset");
const del=document.getElementById("del");
const eq=document.getElementById("eq");
const txt=document.getElementById("text");
const dis=document.getElementById("dis");
const nums=document.getElementById("buttons2");
const btns=document.getElementById("buttons");
const btns2=document.getElementById("buttons2");
function deleteletter() {
    cal.display.value=cal.display.value.slice(0,cal.display.value.length-1);
}
function changeBackground() {
    b.style.backgroundColor=this.backgroundColor;
}
function Change1() {
    b.style.backgroundColor="#4d4dff";
    for(let i=0;i<15;i++)
    {
        numbers[i].style.backgroundColor="#ffffcc"
        numbers[i].style.color="black"
    }
    
    del.style.backgroundColor="#4d4dff";
    res.style.backgroundColor="#4d4dff";
    eq.style.backgroundColor="#e67300";
    res.style.color="black";
    eq.style.color="black";
    del.style.color="black";
    txt.style.color="white";
    dis.style.color="white";
    dis.style.backgroundColor="#00004d";
    nums.style.backgroundColor="#002b80";
    btns.style.backgroundColor="#6666ff";
    btns2.style.backgroundColor="#00004d";
}
function Change2() {
    b.style.backgroundColor="#d1d1e0";
    for(let i=0;i<15;i++)
    {
        numbers[i].style.backgroundColor="#ffffcc"
        numbers[i].style.color="black"
    }
    
    del.style.backgroundColor="#26734d";
    res.style.backgroundColor="#26734d";
    eq.style.backgroundColor="#e67300";
    res.style.color="black";
    eq.style.color="black";
    del.style.color="black";
    txt.style.color="black";
    dis.style.color="black";
    dis.style.backgroundColor="white";
    nums.style.backgroundColor="#002b80";
    btns.style.backgroundColor="#6666ff";
    btns2.style.backgroundColor="#b3b3cc";
}

function Change3() {
    b.style.backgroundColor="#19194d";
    for(let i=0;i<15;i++)
    {
        numbers[i].style.backgroundColor="#6666ff";
        numbers[i].style.color="#e6e600";
    }
    del.style.backgroundColor="#4d4dff";
    res.style.backgroundColor="#4d4dff";
    eq.style.backgroundColor="#e67300";
    res.style.color="#e6e600";
    eq.style.color="#e6e600";
    del.style.color="#e6e600";
    txt.style.color="#e6e600";
    dis.style.color="#e6e600";
    dis.style.backgroundColor="#9999ff";
    nums.style.backgroundColor="#002b80";
    btns2.style.backgroundColor="#9999ff";
}