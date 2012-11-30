<div class="auth-block">
    <h1>Contato</h1>

    <form action="/" method="POST">
        <div style="display:none"><input type="hidden" name="csrfmiddlewaretoken" value=""></div>

        <div class="form-row">
            <label for="nome">Nome:</label>
            <input required type="nome" name="nome" id="nome"/>
        </div>

        <div class="form-row">
            <label for="username">Email:</label>
            <input required="" type="email" name="username" id="username">
        </div>

        <div class="form-row">
            <label for="comentario">Comentario:</label>
            <textarea class="comentario" rows="15" cols="30"></textarea>
        </div>

        <button type="submit" name="contato" class="btn btn-primary">Enviar!</button>
        <div class="clear"></div>
    </form>
</div>
