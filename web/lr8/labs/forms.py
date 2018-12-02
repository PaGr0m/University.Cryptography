from django.forms import ModelForm, Textarea
from django import forms
from .models import Order, Image


class OrderForm(ModelForm):
    class Meta:
        model = Order
        fields = ["fio", "password", "disk", "course", "delivery", "address"]
        # fields = ["disk", "course"]
        widgets = {
            "fio": forms.TextInput(attrs={"class": "form-control"}),
            "password": forms.TextInput(attrs={"class": "form-control"}),
            "disk": forms.RadioSelect(),
            "course": forms.CheckboxSelectMultiple(),
            "delivery": forms.Select(attrs={"class": "form-control"}),
            "address": forms.Textarea(attrs={"class": "form-control"})
        }
# radio attrs={"class": "form-check-input", "type": "radio"}
# check attrs={"class": "form-check-input", "type": "checkbox"}

# form-group form-check


class ImageForm(ModelForm):
    class Meta:
        model = Image
        fields = ["image"]
        # widgets = {
        #     "image": forms.ImageField(attrs={'multiple': True})
        # }

    def save(self):
        new_img = Image.objects.create(
            image=self.cleaned_data["image"]
        )
        return new_img
