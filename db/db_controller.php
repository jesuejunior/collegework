<?php

    require_once "connect.php";

    function cadastra_cliente($nome,$dt_nascimento, $endereco, $email, $senha){
        global $conn;

        $sql = "SELECT COUNT(*) FROM cliente WHERE email = '$email'";
        $query = mysql_query($sql, $conn);
        $total = mysql_fetch_array($query);
        if ($total[0] > 0) {
            print_r('Cliente já existe');
            return false;
        }else{

            $query = "INSERT INTO cliente ( nome, dt_nascimento, endereco , email, senha )
             VALUES ('$nome', STR_TO_DATE('$dt_nascimento','%d/%m/%Y'), '$endereco', '$email', '$senha')";

            mysql_query($query, $conn);
            mysql_close($conn);

            return true;
        }

    }

    function menu(){
        global $conn;
        $sql_plataforma = "select id,nome from plataforma";
        $sql_categoria = "select id,nome from categoria";

        $plataforma = mysql_query($sql_plataforma, $conn);
        $categoria = mysql_query($sql_categoria, $conn);

        $array_plataforma = array();
        $array_categoria = array();
        while($row=mysql_fetch_array($plataforma, MYSQL_ASSOC)){
            array_push($array_plataforma, $row);
        }
        while($row2=mysql_fetch_array($categoria, MYSQL_ASSOC)){
           array_push($array_categoria, $row2);
        }
        $dados = array('plataformas' => $array_plataforma, 'categorias' => $array_categoria);
        mysql_close($conn);
        return $dados;
    }

    function pesquisa($plataforma, $categoria){
        global $conn;
        if($categoria){
            $query = "select * from jogo where id_plataforma = $plataforma AND id_categoria = $categoria";
        }else{
            $query = "select * from jogo where plataforma = $plataforma";
        }
        $jogo = mysql_query($query, $conn);

        if($jogo){
            $jogos = array();
            while($row=mysql_fetch_array($jogo, MYSQL_ASSOC)){
                $categoria_jogo = $row['id_categoria'];
                $plataforma_jogo = $row['id_plataforma'];
                $fabricante_jogo = $row['id_fabricante'];

                $descricoes = mysql_fetch_array(mysql_query("select c.nome,f.nome,p.nome from categoria c join fabricante f
                join plataforma p where c.id = $categoria_jogo and f.id = $fabricante_jogo and p.id = $plataforma_jogo ;", $conn));

                $row['id_categoria'] = $descricoes[0];
                $row['id_plataforma'] = $descricoes[2];
                $row['id_fabricante'] = $descricoes[1];

                array_push($jogos, $row);
            }
            $dados = array('jogos' => $jogos);
            mysql_close($conn);
            return $dados;
        }
        return false;
    }

    function get_game($id){
        global $conn;
        $sql = "select * from jogo where id = $id";
        $query = mysql_query($sql, $conn);

        $jogo = mysql_fetch_array($query, MYSQL_ASSOC);

        $categoria_jogo = $jogo['id_categoria'];
        $plataforma_jogo = $jogo['id_plataforma'];
        $fabricante_jogo = $jogo['id_fabricante'];

        $descricoes = mysql_fetch_array(mysql_query("select c.nome,f.nome,p.nome from categoria c join fabricante f
                join plataforma p where c.id = $categoria_jogo and f.id = $fabricante_jogo and p.id = $plataforma_jogo ;", $conn));

        $jogo['id_categoria'] = $descricoes[0];
        $jogo['id_plataforma'] = $descricoes[2];
        $jogo['id_fabricante'] = $descricoes[1];

        return $jogo;

    }

    function login_cliente($user, $password){
        global $conn;

        // Procura por usuários com o mesmo usuário e senha
        $sql = "SELECT COUNT(*)
                FROM sixgames.cliente
                WHERE
                    email = '$user'
                    AND
                    senha = '$password'";
        $query = mysql_fetch_array(mysql_query($sql, $conn));

        if ($query[0] > 0 ) {
            $total = $query[0];
        } else {
            return false;
        }
        // Se houver apenas um usuário, retorna true

        return ($total == 1) ? true : false;
    }

    function home(){
        global $conn;
        $sql = "select * from jogo limit 3";

        $jogo = mysql_query($sql, $conn);

        if($jogo){
            $jogos = array();
            while($row=mysql_fetch_array($jogo, MYSQL_ASSOC)){
                $categoria_jogo = $row['id_categoria'];
                $plataforma_jogo = $row['id_plataforma'];
                $fabricante_jogo = $row['id_fabricante'];

                $descricoes = mysql_fetch_array(mysql_query("select c.nome,f.nome,p.nome from categoria c join fabricante f
                join plataforma p where c.id = $categoria_jogo and f.id = $fabricante_jogo and p.id = $plataforma_jogo ;", $conn));

                $row['id_categoria'] = $descricoes[0];
                $row['id_plataforma'] = $descricoes[2];
                $row['id_fabricante'] = $descricoes[1];

                array_push($jogos, $row);
            }
            $dados = array('jogos' => $jogos);
            mysql_close($conn);
            return $dados;
        }
        return false;


    }
?>