from django.core.exceptions import ValidationError
from django.forms import ModelForm, Textarea
from django import forms
from .models import Order, ImageModel, MailModel, Auth, RegExpModel

import re
import requests


class OrderForm(ModelForm):
    class Meta:
        model = Order
        fields = ["fio", "password", "disk", "course", "delivery", "address"]
        widgets = {
            "fio": forms.TextInput(attrs={"class": "form-control"}),
            "password": forms.TextInput(attrs={"class": "form-control"}),
            "disk": forms.RadioSelect(),
            "course": forms.CheckboxSelectMultiple(),
            "delivery": forms.Select(attrs={"class": "form-control"}),
            "address": forms.Textarea(attrs={"class": "form-control"})
        }


class ImageForm(ModelForm):
    class Meta:
        model = ImageModel
        fields = ["image"]


class MailForm(ModelForm):
    class Meta:
        model = MailModel
        fields = ["fio", "message"]


class AuthForm(ModelForm):
    class Meta:
        model = Auth
        fields = ["login", "password"]


class RegExpForm(ModelForm):
    class Meta:
        model = RegExpModel
        fields = ["form_1", "form_2", "form_3",
                  "form_4", "form_5", "form_6",
                  "form_8", "form_9"]
        # fields = ["form_9"]
        widgets = {
            "form_1": forms.TextInput(attrs={"class": "form-control"}),
            "form_2": forms.TextInput(attrs={"class": "form-control"}),
            "form_3": forms.TextInput(attrs={"class": "form-control"}),
            "form_4": forms.TextInput(attrs={"class": "form-control"}),
            "form_5": forms.TextInput(attrs={"class": "form-control"}),
            "form_6": forms.TextInput(attrs={"class": "form-control"}),
            "form_7": forms.TextInput(attrs={"class": "form-control"}),
            "form_8": forms.TextInput(attrs={"class": "form-control"}),
            "form_9": forms.TextInput(attrs={"class": "form-control"}),
        }

    # a
    def clean_form_1(self):
        new_form_1 = self.cleaned_data["form_1"]
        reg_a = re.compile(r'a+b*')

        if not reg_a.findall(new_form_1):
            raise ValidationError("RegExp 1. Error")
        return new_form_1

    # b
    def clean_form_2(self):
        new_form_2 = self.cleaned_data["form_2"]
        reg_b = re.compile(r'\\*\**')

        if not reg_b.findall(new_form_2):
            raise ValidationError("RegExp 2. Error")
        return new_form_2

    # c
    def clean_form_3(self):
        new_form_3 = self.cleaned_data["form_3"]
        pattern = 'how'
        reg_c = re.compile('({pattern})'.format(pattern=pattern) + r'{3}')

        if not reg_c.search(new_form_3):
            raise ValidationError("RegExp 3. Error")
        return new_form_3

    # d
    def clean_form_4(self):
        new_form_4 = self.cleaned_data["form_4"]
        reg_d = re.compile(r'.{5}')

        if not reg_d.findall(new_form_4):
            raise ValidationError("RegExp 4. Error")
        return new_form_4

    # e
    def clean_form_5(self):
        new_form_5 = self.cleaned_data["form_5"]
        reg_c = re.compile(r'\b(\S+)[\s]+(\1)\b')

        print(reg_c.findall("\n\n\n\n\n"))
        if not reg_c.findall(new_form_5):
            raise ValidationError("RegExp 5. Error")
        return new_form_5

    # color
    def clean_form_6(self):
        new_form_6 = self.cleaned_data["form_6"]

        color = re.compile('^#[0-9A-F]{6}')

        if not color.findall(new_form_6):
            raise ValidationError("RegExp 6. Error")
        return new_form_6

    # custom
    def clean_form_7(self):

        d = """\n\n\n\nher\n\n\n\n"""

        reg_d = re.compile(r'(.|\n){6}')
        result_d = reg_d.findall(d)
        # print(reg_d)
        # print(result_d)

        result = re.match(r'(.|\n){6}', d)
        print(result)

    # smile
    def clean_form_8(self):
        new_form_8 = self.cleaned_data["form_8"]
        smile = re.compile(r'([:;]-*(\)|\(|\]|\[)\2*)')

        if not smile.findall(new_form_8):
            raise ValidationError("RegExp 8. Error")
        return new_form_8

    # ip
    def clean_form_9(self):
        new_form_9 = self.cleaned_data["form_9"]

        ip = re.compile(r'(?:(?:\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])\.){3}(?:\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])')

        if not ip.findall(new_form_9):
            raise ValidationError("RegExp 9. Error")
        return new_form_9
