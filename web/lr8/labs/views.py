from django.shortcuts import render, redirect
from .forms import OrderForm
from django.views.decorators.csrf import csrf_exempt

def initial_forms(request):
    order_form = OrderForm
    args = {}
    # args.update(csrf(request))
    args["form"] = order_form

    return render(request,
                  "labs/order.html",
                  args)


@csrf_exempt
def create_order(request):
    form = OrderForm(request.POST)
    feedback = form.save()

    return render(request,
                  "labs/success.html")
