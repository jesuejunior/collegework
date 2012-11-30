<html>
<body>

<?php
    include "db/connect.php";


    $sql = "SELECT * FROM tipo_operacao";
    $res = mysql_query($sql);

    $conteudo = mysql_fetch_array($res);

    $linhas = mysql_num_rows($res);

while($linhas = $conteudo){

echo "ID: " .$conteudo["id"] ."<br/>";
echo "Nome: " .$conteudo["nome"] ."<br/>";

}

    mysql_close($conexao);
    mysql_free_result($res);
?>
</body>
</html>

