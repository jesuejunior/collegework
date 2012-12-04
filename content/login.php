<div class="auth-block">
    <h1>Login</h1>

    <form action="form/loginForm.php" method="POST">
        <div style="display:none"><input type="hidden" name="csrfmiddlewaretoken" value=""></div>

        <div class="form-row">
            <label for="email">Email:</label>
            <input required="" type="email" name="email" value="" id="email" class="check-mail">
        </div>

        <div class="form-row">
            <label for="password">Password:</label>
            <input required="" type="password" name="password" id="password">
        </div>

        <button type="submit" name="submit" class="btn btn-success">Entrar!</button>
        <div class="clear"></div>
    </form>
</div>
<script type="text/javascript">

</script>