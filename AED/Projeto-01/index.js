$('#formAddToCheckout').submit(
    function(evt){
        var input_code_checkout = $("#input_code_checkout").val();
        alert(input_code_checkout);
        //CAL ADD FUNCTION
        addToCheckOut(input_code_checkout);
        input_code_checkout.val();
        evt.preventDefault();
    }
)


function addToCheckOut(prod_code) {
    //Search Code to get name
    var obj = {"code": prod_code};
    localStorage.setItem('Checkout', JSON.stringify(obj));
}

function addToStock(prod_code, prod_name, prod_price, prod_quantity){
    var obj = {"code": prod_code, "name": prod_name, "price": prod_price, "quantity": prod_quantity};
    localStorage.setItem('Stock', JSON.stringify(obj));
}

// var obj = JSON.parse(localStorage.getItem('Stock'));