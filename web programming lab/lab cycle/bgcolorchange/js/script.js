function changeBgColor() {
    document.getElementById("body").style.backgroundColor =
        getRandomColor();
}

function getRandomColor() {
    var colorcode = "#";
    for (let i = 1; i <= 3; i++) {
        let index = Math.floor(Math.random() * 255);
        //getting random value between 0 and 255;
        let randomChar = index.toString(16);
        //converting the value to hexcode of length2
        colorcode = colorcode + randomChar;
    }
    return colorcode;
}