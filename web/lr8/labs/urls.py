from django.contrib import admin
from django.urls import path
from . import views


urlpatterns = [
    path("main/", views.initial_forms),
    path("order/create/", views.create_order)
]
