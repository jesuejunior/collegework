/**
 * Created with JetBrains WebStorm.
 * User: jesuejunior
 * Date: 9/20/12
 * Time: 3:11 PM
 * To change this template use File | Settings | File Templates.
 */

function myFunc(plataforma, categoria){
    pagina = plataforma.trim()+'\/' +categoria.trim()+'.html';
    $.get(pagina, function(data){
        $("#content").html(data);
    });
};
