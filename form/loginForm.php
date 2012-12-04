<?php

include "../db/db_controller.php";


$user = $_POST['email'];
$password = $_POST['password'];

$resultado = login_cliente($user, $password);

if($resultado){
    header("Location: /sixgames");

}else{
    header("Location: /sixgames");
}
?>