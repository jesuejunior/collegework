<?php

function valida_data($data)
{
    $data = split("[-,/]", $data);
    if(!checkdate($data[1], $data[0], $data[2]) and !checkdate($data[1], $data[2], $data[0])) {
        return false;
    }
    return true;
}


?>