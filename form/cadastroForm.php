<?php

include "../db/db_controller.php";

$nome = $_POST['nome'];
$dt_nascimento = $_POST['t_nascimento'];
$endereco = $_POST['endereco'];
$email = $_POST['email'];
$senha = $_POST['senha'];

$resultado = cadastra_cliente($nome,$dt_nascimento, $endereco, $email, $senha);

echo "Cadastro realizado com sucesso. Bem vindo:" .$nome;
?>