<?php

function valida_data($data)
{
    $data = split("[-,/]", $data);
    if(!checkdate($data[1], $data[0], $data[2]) and !checkdate($data[1], $data[2], $data[0])) {
        return false;
    }
    return true;
}

function converte_data($data)
{
    if(valida_data($data)) {
        return implode(!strstr($data, '/') ? "/" : "-", array_reverse(explode(!strstr($data, '/') ? "-" : "/", $data)));
    }
}

?>