from django.db import models
from django.contrib.postgres.fields import ArrayField


class Order(models.Model):
    DELIVERY_CHOICES = {
        ("Быстрая", "Быстрая"),
        ("Бесплатная", "Бесплатная"),
    }

    fio = models.CharField(verbose_name="ФИО",
                           max_length=30)
    password = models.CharField(verbose_name="Пароль",
                                max_length=10)
    disk = models.CharField(verbose_name="Диск",
                            max_length=3)
    course = ArrayField(ArrayField(models.CharField(verbose_name="Курсы",
                                                    max_length=20)))
    delivery = models.CharField(verbose_name="Способ доставки",
                                max_length=20,
                                choices=DELIVERY_CHOICES)
    address = models.TextField(verbose_name="Введите адрес доставки")
