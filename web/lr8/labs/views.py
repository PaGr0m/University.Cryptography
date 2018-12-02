from django.shortcuts import render, redirect
from django.views.generic import View

from django.views.decorators.csrf import csrf_exempt

from .models import Order, Image
from .forms import OrderForm, ImageForm
from .utils import ObjectCreateMixin


# class OrderView(View):
#     def get(self, request):
#         form = OrderForm
#         context = {
#             "form": form
#         }
#
#         return render(request=request,
#                       template_name="labs/order_create.html",
#                       context=context)
#

def order_list(request):
    order = Order.objects.all()
    context = {
        "orders": order
    }
    return render(request=request,
                  template_name="labs/order_list.html",
                  context=context)


class OrderCreate(ObjectCreateMixin, View):
    model_form = OrderForm
    template = "labs/order_create.html"


def initial_forms(request):
    order_form = OrderForm
    args = {
        "form": order_form
    }

    return render(request=request,
                  template_name="labs/order_create.html",
                  context=args)


def create_order(request):
    form = OrderForm(request.POST)
    feedback = form.save()

    return render(request,
                  "labs/success.html")


def create_image(request):
    form = ImageForm
    context = {
        "form": form
    }

    return render(request=request,
                  template_name="labs/image_field.html",
                  context=context)


def show_image(request):
    image = Image.objects.all()
    context = {
        "images": image
    }
    return render(request=request,
                  template_name="labs/image_list.html",
                  context=context)

