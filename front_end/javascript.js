
$(document).ready(function(){
    createSwitch(10);
    showTime();   
});


function createSwitch(foundSwitches){
    let x = foundSwitches;
    for(let i = 0; i < x; i++){                
        //Creates the toggle
        //toggle -> child[0]: checkbox
        //toggle -> child[1]: span
        let toggle = document.createElement("label");
        toggle.setAttribute("class", "switch");
        toggle.setAttribute("id", "toggle"+i);
        
        
        let checkbox = document.createElement("INPUT");
        checkbox.setAttribute("type", "checkbox");
//        checkbox.setAttribute("onchange", check);
//        checkbox.setAttribute("id", "checked");
        
        let span = document.createElement("SPAN");
        span.setAttribute("class", "slider");
        
        toggle.appendChild(checkbox);
        toggle.appendChild(span);

        
        //creates textArea
        let textArea = document.createElement("INPUT");
        textArea.setAttribute("type", "text");
        textArea.placeholder = "Give this Switch a name";
        
        //creates savebutton
        let buttonSave = document.createElement("BUTTON");
        buttonSave.innerHTML = "Save";
        buttonSave.setAttribute("class", "buttonSave");
        buttonSave.addEventListener('click', setName);
        
        
        buttonSave.addEventListener('click', checkTime);
        
        //creates options button
        let buttonOptions =document.createElement("BUTTON");
        buttonOptions.innerHTML = "Options";
        buttonOptions.setAttribute("id", "buttonOptions" + x);
        buttonOptions.addEventListener('click', displayOptions);
        
        //FIXME
        //creates dropdown list for options button
//        let setSchedule = document.createElement("UL");
//        setSchedule.innerHTML = "Set Schedule";
////        ul.style.display = "none";   
//        buttonOptions.appendChild(setSchedule);
//        let del = document.createElement("UL");
//        del.innerHTML = "delete";
//        buttonOptions.appendChild(del);
        
        //creates the ID label
        let p = document.createElement("P");
        p.innerHTML = "ID: " + i + " ";
        
        
        let value = document.createElement("P");
        value.style.visibility = "hidden";
        value.innerHTML = "-1";
        value.setAttribute("class", "timeOut");
        
        //adds each into a div container
        let div = document.createElement("DIV");
        div.appendChild(toggle);
        div.appendChild(buttonSave);
        div.appendChild(buttonOptions);
        div.appendChild(textArea);
        div.appendChild(p);
        div.appendChild(value);
        document.body.appendChild(div);
    }   
}


function setName(){   
    //Savebutton -> options -> *textArea* -> ID
    let name = $(this).next().next().val();  
    if(!(name === "")){
//toggle -> Savebutton -> options -> textArea -> *ID*
       $(this).next().next().next().html(name); 
    }
    if(this.previousSibling.firstChild.checked){
        on();
//        alert("turned on");
    }
    else{
        off();
//        alert("turned off");
    }


}

function on(){
    var url ="http://192.168.43.105/?lighton";
    open(url);

}

function off(){
    var url2 ="http://192.168.43.105/?lightoff";
    open(url2);
}

function displayOptions(){
    $(this).children.toggle("show");
}

function showTime(){
    let date = new Date();
    let mo = date.getMonth();
    let d = date.getDay();
    let h = date.getHours(); // 0 - 23
    let min = date.getMinutes(); // 0 - 59
    let s = date.getSeconds(); // 0 - 59
    let session = "AM";
    
    
    if (h >= 12){session = "PM";}
    let currentTime = "" + mo + d + h + min;
    
    h = (h < 10) ? "0" + h : h;
    min = (min < 10) ? "0" + min : min;
    s = (s < 10) ? "0" + s : s;
    
    
    checkTime(currentTime);    
    h = standardTime(h);
    
    console.log(d);
    
    let time = mo + "/"+ d + " " + h + ":" + min + ":" + s + " " + session;
    document.getElementById("clockDisplay").innerText = time;
    document.getElementById("clockDisplay").textContent = time;
    
    setTimeout(showTime, 1000); 
    
}

function checkTime(currentTime){
    let currentT = parseInt(currentTime);
    let timeArray = document.getElementsByClassName("timeOut");
    //console.log(timeArray);
    
    for(let i=0; i< timeArray.length; i++){
            let time = parseInt(timeArray[i].innerHTML);
//            console.log(time);
//            console.log(currentT);
            if(time != -1){
//                console.log(time);
            if(time < currentT){
               timeArray[i].parentNode.firstChild.firstChild.checked = false;
            }
            else{
                timeArray[i].parentNode.firstChild.firstChild.checked = true;

            }

            } 
        }
}

function standardTime(hour){
    if(hour == 0){
        hour = 12;
    }
    
    if(hour > 12){
        hour = hour - 12;
        session = "PM";
    }
    return hour;
}
    