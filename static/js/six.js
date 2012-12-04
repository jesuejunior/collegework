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
    var reg_email = new RegExp(/^[A-Za-z0-9_\-\.]+@[A-Za-z0-9_\-\.]{2,}\.[A-Za-z0-9]{2,}(\.[A-Za-z0-9])?/);
    return reg_email.test(email)
}

function check_date(DATA) {

    var reg_data = /^(0?[1-9]|[12][0-9]|3[01])[\/\-](0?[1-9]|1[012])[\/\-]\d{4}$/;
    var datas = /(0[0-9]|[12][0-9]|3[01])[-\.\/](0[0-9]|1[012])[-\.\/][0-9]{4}/;
    if(reg_data.test(DATA.value)){
        $('#dt_nascimento').removeClass('feedback error');
    }else{
        $('#dt_nascimento').addClass('feedback error').focus();
    }

}

$('.jogos').live('click', function(e){
    e.preventDefault();
    var jogos = $(this).attr('dados');

    $.ajax({
        type: 'POST',
        url: "ajax.php?func=pesquisa",
        data: jogos,
        success:function(data){
            $('#content .container').html(_.template($("#game-content").html())(data));
        },
        error:function(data){
            console.log('ERRO');
        }
    });

});

$('.game').live('click', function(e){
    e.preventDefault();
    var id = $(this).attr('idgame');

    $.ajax({
        type: 'POST',
        url: "ajax.php?func=get_game",
        data:  {id:id},
        success:function(data){
            console.log(data);
            $('#content .container').html(_.template($("#game").html())(data));
        }
    })
});


$('.check_nome').live("blur", function(e){
    e.preventDefault();
    var nome = document.getElementById('nome').value;
    if((nome == '') || (nome.length < 4) ){
        $('.check_nome').addClass('feedback error').focus();
    }else{
        $('.check_nome').removeClass('feedback error');
    }
});

$('.check_pass').live("mouseup", function(e){
    e.preventDefault();
    var senha = document.getElementById('nome').value;
    if((senha == '') || (senha.length < 4) ){
        $('.check_pass').addClass('feedback error').focusout();
    }else{
        $('.check_pass').removeClass('feedback error');
    }
});


$('.check-mail').live("blur",function(){
    var email = document.getElementById('email').value;
    if(check_mail(email)){
        $('.check-mail').removeClass('feedback error');
    }else{
        $('.check-mail').addClass('feedback error').focus();
        $('.feedback').removeAttr('hidden');

    }

});

function isNumberKey(inputData, evt)
{
    var charCode = (window.event)?event.keyCode:evt.which;

    if ((charCode>44 && charCode<58) || charCode==8 || charCode==0){
        var data = inputData.value;
        if (data.length == 2 || data.length == 5){
            data += '/';
            inputData.value = data;
        }
        return true;
    }
    return false;
}

$(document).ready(function() {

    $.ajax({
        type: 'GET',
        url: "ajax.php?func=menu",

        success:function(data){
            $('#menu').html(_.template($("#template").html())(data));
        }
    });

    $(".ieie").click(ajax_link);
    $("#login_button").click(ajax_link);
    $("#subscribe_button").click(ajax_link);
    $("#comprar").click(ajax_link);

    $.ajax({
        type: 'GET',
        url: "ajax.php?func=home",

        success:function(data){
            $('#content .container').html(_.template($("#game-content").html())(data));
        }
    });
    

});
