<!DOCTYPE html >
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>.::Six Games::. Sua loja de jogos!</title>
    <link rel="stylesheet" type="text/css" href="static/css/six.css" />
    <link rel="stylesheet" type="text/css" href="static/css/lightbox.css" />
    <script src="static/js/jquery-1.7.min.js" type="text/javascript"></script>
    <script src="static/js/modernizr.custom.js" type="text/javascript"></script>
    <script src="static/js/underscore-min.js" type="text/javascript"></script>
    <script src="static/js/lightbox.js" type="text/javascript"></script>
    <script src="static/js/six.js" type="text/javascript"></script>
</head>
<body>

<header id="six_header">
    <div id="header-top" class="container">


        <a href="/sixgames" id="logo" title="Six Games"><img src="static/img/6games.png"/> </a>
        <form id="header_search" action="" class="search">
            <input id="six_header_search_bar" type="text" placeholder="Digite o nome do jogo" name="q" autocomplete="off" />
            <button class="btn btn-warning btn-large">BUSCAR</button>
        </form>

        <div class="user_line">
            <ul>
                <li><a href="content/register.php" id="subscribe_button" class="btn btn-primary">Cadastre-se</a></li>
                <li class="last">
                    <a href="content/login.php" id="login_button" class="btn btn-primary">Login</a>
                </li>
            </ul>
        </div>

        <div class="clear"></div>
    </div>

    <nav id="menu"></nav>

    <script type="text/template" id="template">
        <div class="container">
            <ul class="meio">
                <% _.each(plataformas, function(plataforma) { %>

                <li><a href="<%= plataforma.nome %>" dados="plataforma=<%= plataforma.id %>" class="plataforma" title="<%= plataforma.nome %>"><%= plataforma.nome %></a>
                    <ul>
                        <% _.each(categorias, function(categoria, index, list) { %>
                        <li <% if(index == list.length-1) { print ("class='last'"); } %> >
                            <a href="<%= categoria.nome %>" class="ieie jogos" dados="plataforma=<%= plataforma.id %>&categoria=<%= categoria.id %>"
                               title="<%= categoria.nome %>"><%= categoria.nome %></a>
                        </li>
                        <% }); %>
                    </ul>
                </li>
                <% }); %>
            </ul>
        </div>
    </script>
    <script type="text/template" id="game-content">

        <div class="imageRow">
            <ul>
                <% _.each(jogos, function(jogo){%>
                <li class="six_title">
                    <div class="single" >
                        <input type="hidden" id="title" value="">
                        <a href="#" class="game"  idgame="<%= jogo.id %>" title="<%= jogo.nome%>"><img src="static/<%= jogo.img_small %>" alt="<%= jogo.nome%>"></a>
                        <div class="six_title" >
                            <p><strong class="six_title" ><%= jogo.nome%></strong></p>
                        </div>
                        <div class="six_title">
                            <p > <%= jogo.id_categoria %> -- <strong><%= jogo.id_plataforma %></strong></p>
                        </div>
                        <div class="">
                            <p>A partir de:</p>
			<span class="">
				<span class="price"> R$ <%= jogo.pr_compra %></span>
			</span>
                        </div>
                    </div>
                </li>
                <% }); %>
            </ul>
            <div class="clear"></div>
        </div>
    </script>
    <script type="text/template" id="game">

        <div class="game">
            <a href="static/<%= img_large %>" class="game_foto" rel="lightbox" title="<%= nome %>"> <img src="static/<%= img_small %>" alt="<%= nome %>"/> </a>
            <div class="actions">
                <h1>Uncharted 3: Drake's Deception</h1>
                <span class="price">R$ <%= pr_compra %></span>
                <div class="buttons">
                    <a href="content/login.php" id="comprar" class="btn btn-warning">Comprar</a>
                    <a href="javascript:open_ajax_link('content/login.php');" id="reservar" class="btn btn-success">Reservar</a>
                    <a href="javascript:open_ajax_link('content/login.php');" id="alugar" class="btn btn-success">Alugar</a>
                    <a href="javascript:open_ajax_link('content/login.php');" id="jogar_online" class="btn btn-success">Jogar Online</a>
                </div>
            </div>
            <div class="clear"></div>
            <div class="game_description">
                <p><%= descricao %>
                </p>
                <ul class="game_info">
                    <li>Tipo de jogo: <%= id_categoria %></li>
                    <li>Desenvolvedora: <%= id_fabricante %></li>
                </ul>
            </div>
        </div>


    </script>

</header>
<div id="content">
    <div class="container categories-content">
    <div class="feedback" hidden="">Algum campo ainda está com erro. Por favor verifique.</div>

    </div>

</div>


<footer>
     <div class="container">
         <a href="javascript:open_ajax_link('');" class="btn btn-large btn-primary">Venda</a>
         <a href="javascript:open_ajax_link('');" class="btn btn-large btn-primary">Locação</a>
         <a href="javascript:open_ajax_link('content/contato.php');" class="btn btn-large btn-primary">Contato</a>
     </div>
    <div class="container">
        <hr/>

        Copyright SixGames 2012, Six Games
    </div>

</footer>
</body>
</html>