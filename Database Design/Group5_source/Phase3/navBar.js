$(document).ready(function(){
    var container = document.createElement("div");
    container.setAttribute("id", "navBar");
    container.setAttribute("class", "clear");
    document.body.appendChild(container);
    $("#navBar").html("<span class='pageLabel'>Functions</span> <a href='insert.html' class='publicPages' id='insertPage'>Insert</a> <a href='delete.html' class='publicPages' id='deletePage'>Delete</a> <a href='modify.html' class='publicPages' id='modifyPage'>Modify</a> <a href='queries.html' class='publicPages' id='queriesPage'>Queries and Aggregates</a>");
});


