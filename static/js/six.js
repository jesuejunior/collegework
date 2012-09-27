/**
 * Created with JetBrains WebStorm.
 * User: jesuejunior
 * Date: 9/20/12
 * Time: 3:11 PM
 * To change this template use File | Settings | File Templates.
 */

function open_ajax_link(link){
    $.get(link, function(data){
        $("#content .container").html(data);
    });
    return false;
}

function ajax_link(){
    link = this.href;
    return open_ajax_link(link);
}

function check_mail(email){
    var reg_email = /^[a-zA-Z0-9.\+_-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}$/;
    if(reg_email.exec(email.value)){
        alert("ok");
    }else{
        alert("Wrong");
    }
}

function check_date(DATA) {

    var reg_data = /^(0?[1-9]|[12][0-9]|3[01])[\/\-](0?[1-9]|1[012])[\/\-]\d{4}$/;
    if(reg_data.test(DATA.value)){
        alert('ok');
    }


}

$(function(){
    var data = { listas : [
    {
    nome : "PS3" ,
    items: [
                    {nome: "Acao",     link : 'ps3/acao.html'},
                    {nome: "Aventura", link : 'ps3/aventura.html'},
                    {nome: "Corrida",  link : 'ps3/corrida.html'},
                    {nome: "Shooter",  link : 'ps3/shooter.html'},
                    {nome: "Luta",     link : 'ps3/luta.html'},
                    {nome: "RPG",      link : 'ps3/rpg.html'},
                    {nome: "Esportes", link : 'ps3/esportes.html'},
                    {nome: "Todos",    link : 'ps3/todos_jogos.html'}
]
},
            {
                nome : "XBOX 360" ,
                items: [
                    {nome: "Acao",     link : 'xbox_360/acao.html'},
                    {nome: "Aventura", link : 'xbox_360/aventura.html'},
                    {nome: "Corrida",  link : 'xbox_360/corrida.html'},
                    {nome: "Shooter",  link : 'xbox_360/shooter.html'},
                    {nome: "Luta",     link : 'xbox_360/luta.html'},
                    {nome: "RPG",      link : 'xbox_360/rpg.html'},
                    {nome: "Esportes", link : 'xbox_360/esportes.html'},
                    {nome: "Todos",    link : 'xbox_360/todos_jogos.html'}
]
},
            {
                nome : "WII" ,
                items: [
                    {nome: "Acao",     link : 'wii/acao.html'},
                    {nome: "Aventura", link : 'wii/aventura.html'},
                    {nome: "Corrida",  link : 'wii/corrida.html'},
                    {nome: "Shooter",  link : 'wii/shooter.html'},
                    {nome: "Luta",     link : 'wii/luta.html'},
                    {nome: "RPG",      link : 'wii/rpg.html'},
                    {nome: "Esportes", link : 'wii/esportes.html'},
                    {nome: "Todos",    link : 'wiitodos_jogos.html'}
]
},
            {
                nome : "PC" ,
                items: [
                    {nome: "Acao",     link : 'pc/acao.html'},
                    {nome: "Aventura", link : 'pc/aventura.html'},
                    {nome: "Corrida",  link : 'pc/corrida.html'},
                    {nome: "Shooter",  link : 'pc/shooter.html'},
                    {nome: "Luta",     link : 'pc/luta.html'},
                    {nome: "RPG",      link : 'pc/rpg.html'},
                    {nome: "Esportes", link : 'pc/esportes.html'},
                    {nome: "Todos",    link : 'pc/todos_jogos.html'}
]
}
]};


$(document).ready(function() {
    $('#menu').html(_.template($("#template").html())(data));
    $(".ieie").click(ajax_link);
    $("#login_button").click(ajax_link);
    $("#subscribe_button").click(ajax_link);

    open_ajax_link('content/content.html');

});


})