from django.urls import path
from .views import OrderCreate, ImageCreate, RegExpCreate
from .views import order_list, show_image, create_image, image_form, last_image

from .views import mail_form, mail_send
from .views import auth_init, auth_coockies, auth_user
from .views import regexp_form

urlpatterns = [
    path("order/create", OrderCreate.as_view(), name="order_create_url"),
    path("order/list", order_list, name="musician_list_url"),

    path("image", image_form, name="image_form_url"),
    path("image/create", create_image, name="image_create_url"),
    path("image/last", last_image, name="image_last_url"),
    path("image/list", show_image, name="image_list_url"),

    path("mail", mail_form, name="mail_form_url"),
    path("mail/send", mail_send, name="mail_send_url"),

    path("auth", auth_init, name="auth_url"),
    path("auth/coockies", auth_coockies, name="auth_coockies_url"),
    path("auth/user", auth_user, name="auth_user_url"),

    path("regexp/create", RegExpCreate.as_view(), name="regexp_create_url")
]