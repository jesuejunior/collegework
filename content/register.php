<!DOCTYPE html>
<html>
<head>
    <title></title>
</head>
<body>

<div class="auth-block">
    <h1>Cadastrar Usuario</h1>

    <form name="cadastro" id="cadastro" action="" method="post">

        <div class="form-row">
            <label for="nome">Nome:</label>
            <input required type="text" name="nome" id="nome" value="" class="check_nome"/>
        </div>

        <div class="form-row">
            <label for="dt_nascimento">Data de Nascimento:</label>
            <input onkeypress="return isNumberKey(this, event)" onblur="check_date(this)" type="text" name="dt_nascimento" maxlength="10" id="dt_nascimento"/>
        </div>

        <div class="form-row">
            <label for="endereco">Endereco:</label>
            <input required name="endereco" id="endereco"/>
        </div>

        <div class="form-row">
            <label for="email">E-mail:</label>
            <input required type="email" name="email" id="email" class="check-mail"/>
        </div>

        <div class="form-row">
            <label for="senha">Password:</label>
            <input required type="password" name="senha" id="senha" class="check_pass"/>
        </div>

        <div class="form-row">
            <label for="confirma-senha">Confirm password:</label>
            <input required type="password" name="confirma-senha" id="confirma-senha" class="check_pass"/>
        </div>

        <button type="submit" name="submit" class="ok-btn btn btn-success">Registar!</button>
        <div class="clear"></div>
    </form>

</div>
<script type="text/javascript">

    $('.ok-btn').live("click", function(e){
        e.preventDefault();
        form_data = $('#cadastro').serialize();
        console.log(form_data);
        $.ajax({
            type: 'POST',
            url: 'ajax.php?func=cadastra_cliente',
            data: form_data,
            error:function(data){
                open_ajax_link("erro.php");
                return false;
            },
            success: function(data){
                open_ajax_link("cadastro_sucesso.php");
                return true;
            }

        });
        return false;
    });



</script>
</body>
</html>