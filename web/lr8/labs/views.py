from django.shortcuts import render, redirect
from django.views.generic import View
from django.core.mail import send_mail
from django.views.decorators.csrf import csrf_exempt

from .models import Order, ImageModel, MailModel, Auth
from .forms import OrderForm, ImageForm, MailForm, AuthForm, RegExpForm
from .utils import ObjectCreateMixin


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


class ImageCreate(ObjectCreateMixin, View):
    model_form = ImageForm
    template = "labs/image_field.html"


def image_form(request):
    form = ImageForm
    context = {
        "form": form
    }

    return render(request=request,
                  template_name="labs/image_field.html",
                  context=context)


def create_image(request):
    img = ImageModel(image=request.POST.get("image"))
    img.save()

    return redirect("/labs/image/last")


def show_image(request):
    image = ImageModel.objects.all()
    context = {
        "images": image
    }
    return render(request=request,
                  template_name="labs/image_list.html",
                  context=context)


def last_image(request):
    image = ImageModel.objects.last()
    context = {
        "image": image
    }
    return render(request=request,
                  template_name="labs/image_last.html",
                  context=context)


def mail_form(request):
    form = MailForm
    context = {
        "form": form
    }

    return render(request=request,
                  template_name="labs/mail.html",
                  context=context)


def mail_send(request):
    first = request.POST.get("fio")
    second = request.POST.get("message")

    send_mail(
        first,
        second,
        "pagrom27@gmail.com",
        ["jixe@zsero.com"],
        fail_silently=False
    )

    return render(request=request,
                  template_name="labs/mail.html")


def auth_init(request):
    form = AuthForm
    context = {
        "form": form
    }

    return render(request=request,
                  template_name="labs/auth.html",
                  context=context)


def auth_coockies(request):
    name = request.POST.get("login")
    password = request.POST.get("password")

    response = redirect("/labs/auth")
    response.set_cookie("name", name)
    response.set_cookie("password", password)

    request.session.set_expiry(10)
    request.session["pause"] = True

    user = Auth.objects.create(login=name, password=password)

    return response


def auth_user(request):
    context = {

    }
    if "pause" not in request.session:
        user = Auth.objects.last() # SELECT * FROM labs_auth limit 1 DESC
        context = {
            "user": user
        }

    return render(request=request,
                  template_name="labs/auth_user.html",
                  context=context)


def regexp_form(request):
    form = RegExpForm
    context = {
        "form": form
    }

    return render(request=request,
                  template_name="labs/auth.html",
                  context=context)


class RegExpCreate(ObjectCreateMixin, View):
    model_form = RegExpForm
    template = "labs/regexp.html"
