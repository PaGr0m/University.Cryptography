from django import forms
from django.core.exceptions import ValidationError
from .models import Musician, Song


class MusicianForm(forms.ModelForm):
    def clean_musician(self):
        new_musician = self.cleaned_data["musician"].lower()

        if new_musician == "create":
            raise ValidationError("Musician may not be 'Create'")

    class Meta:
        model = Musician
        fields = ["name", "information"]

        widgets = {
            "name": forms.TextInput(attrs={"class": "form-control"}),
            "information": forms.TextInput(attrs={"class": "form-control"})
        }


class SongForm(forms.ModelForm):
    class Meta:
        model = Song
        fields = ["name", "album", "genre", "musician", "lyrics", "lyrics_ru"]

        widgets = {
            "name": forms.TextInput(attrs={"class": "form-control"}),
            "album": forms.TextInput(attrs={"class": "form-control"}),
            "genre": forms.Select(attrs={"class": "form-control"}),
            "musician": forms.Select(attrs={"class": "form-control"}),
            "lyrics": forms.Textarea(attrs={"class": "form-control"}),
            "lyrics_ru": forms.Textarea(attrs={"class": "form-control"})
        }

