from django.urls import path
from .views import OrderCreate
from .views import order_list, show_image, create_image


urlpatterns = [
    path("order/create", OrderCreate.as_view(), name="order_create_url"),
    path("order/list", order_list, name="musician_list_url"),

    path("image/create", create_image, name="image_create_url"),
    path("image/list", show_image, name="image_list_url")
]