import { NgModule } from "@angular/core";
import { CommonModule } from "@angular/common";
import { HomeComponent } from "./home/home.component";
import { NotfoundComponent } from "./notfound/notfound.component";
import { GradesComponent } from "./grades/grades.component";
import { FormsModule, ReactiveFormsModule } from "@angular/forms";
import { StasisModule } from "../stasis/stasis.module";
import { RedieComponent } from "./redie/redie.component";
import { MarkdownModule } from "ngx-markdown";

@NgModule({
  declarations: [HomeComponent, NotfoundComponent, GradesComponent, RedieComponent],
  imports: [CommonModule, ReactiveFormsModule, MarkdownModule.forChild(), FormsModule, StasisModule],
  exports: [HomeComponent],
})
export class DynaModule {}
