const headerarr=["Discover innovative ways to decorate","We are available all across the globe","Manufactured with the best materials"];
const textarr=["We provide unmatched quality, comfort, and style for property owners across the country.Our experts combine form and function in bringing your vision to life.Create a room in your own style with our collection and make your property a reflection of you and what you love.",
"With stores all over the world, it's easy for you to find furniture for your home or place of business. Locally, we’re in most major cities throughout the country. Find the branch nearest you using our store locator. Any questions? Don't hesitate to contact us today.",
"Our modern furniture store provide a high level of quality. Our company has invested in advanced technology to ensure that every product is made as perfect and as consistent as possible. With three decades of experience in this industry, we understand what customers want for their home and office."];
const imgsrc=["desktop-image-hero-1.jpg","desktop-image-hero-2.jpg","desktop-image-hero-3.jpg"]
const big=document.getElementById("bigText");
const small=document.getElementById("smallText");
const nextbtn=document.getElementById("nextb");
const prevbtn=document.getElementById("prevb");
const left=document.getElementById("leftdiv");
let count=0;
function scrollnext() {
count++;
big.innerHTML = headerarr[count%3];
small.innerHTML = textarr[count%3];
left.style.backgroundImage = "url(" + imgsrc[count%3] + ")";
}
function scrollprev() {
count--;
if (count<0)
{
    count=2;
}
big.textContent = headerarr[count%3];
small.textContent = textarr[count%3];
left.style.backgroundImage = "url(" + imgsrc[count%3] + ")";
}