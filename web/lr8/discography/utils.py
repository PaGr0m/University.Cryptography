from django.shortcuts import redirect, render, reverse
from django.shortcuts import get_object_or_404


class ObjectCreateMixin:
    model_form = None
    template = None

    def get(self, request):
        form = self.model_form
        context = {
            "form": form
        }

        return render(request=request,
                      template_name=self.template,
                      context=context)

    def post(self, request):
        bound_form = self.model_form(request.POST)
        context = {
            "form": bound_form
        }

        if bound_form.is_valid():
            new_obj = bound_form.save()
            return redirect(new_obj)

        return render(request=request,
                      template_name=self.template,
                      context=context)


class ObjectReadMixin:
    model = None
    template = None

    def get(self, request, slug):
        obj = get_object_or_404(self.model, slug__iexact=slug)
        context = {
            self.model.__name__.lower(): obj,
            "admin_obj": obj,
            "show": True
        }

        return render(request=request,
                      template_name=self.template,
                      context=context)


class ObjectUpdateMixin:
    model = None
    model_form = None
    template = None

    def get(self, request, slug):
        obj = self.model.objects.get(slug__iexact=slug)
        bound_form = self.model_form(instance=obj)
        context = {
            "form": bound_form,
            self.model.__name__.lower(): obj
        }
        return render(request=request,
                      template_name=self.template,
                      context=context)

    def post(self, request, slug):
        obj = self.model.objects.get(slug__iexact=slug)
        bound_form = self.model_form(request.POST, instance=obj)
        context = {
            "form": bound_form,
            self.model.__name__.lower(): obj
        }

        if bound_form.is_valid():
            new_obj = bound_form.save()
            return redirect(new_obj)

        return render(request=request,
                      template_name=self.template,
                      context=context)


class ObjectDeleteMixin:
    model = None
    template = None
    redirect_url = None

    def get(self, request, slug):
        obj = self.model.objects.get(slug__iexact=slug)
        context = {
            self.model.__name__.lower(): obj
        }

        return render(request=request,
                      template_name=self.template,
                      context=context)

    def post(self, request, slug):
        obj = self.model.objects.get(slug__iexact=slug)
        obj.delete()

        return redirect(reverse(self.redirect_url))
