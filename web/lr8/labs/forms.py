from django.forms import ModelForm, Textarea
from django import forms
from .models import Order


class OrderForm(ModelForm):

    class Meta:
        model = Order

        # fields = ['fio', 'password']
        fields = "__all__"
        widgets = {
            'name': Textarea(attrs={'cols': 80,
                                    'rows': 20}),
        }

# class OrderForm(forms.Form):
#     a = forms.CharField(max_length=100)
#     b = forms.Textarea()
#     c = forms.CharField(max_length=50)

