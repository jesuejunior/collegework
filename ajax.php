<?php
include 'db/db_controller.php';

$func = $_GET['func'];

$response = call_user_func_array($func, $_POST);

header('Content-Type: application/json');
echo json_encode($response);

?>