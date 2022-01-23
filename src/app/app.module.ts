import { HttpClient, HttpClientModule } from "@angular/common/http";
import { NgModule, SecurityContext } from "@angular/core";
import { BrowserModule } from "@angular/platform-browser";
import { MarkdownModule } from "ngx-markdown";

import { AppRoutingModule } from "./app-routing.module";
import { AppComponent } from "./app.component";
import { DynaModule } from "./dyna/dyna.module";
import { StasisModule } from "./stasis/stasis.module";

@NgModule({
  declarations: [AppComponent],
  imports: [
    HttpClientModule,
    MarkdownModule.forRoot({ loader: HttpClient, sanitize: SecurityContext.NONE }),
    BrowserModule,
    AppRoutingModule,
    StasisModule,
    DynaModule,
  ],
  providers: [],
  bootstrap: [AppComponent],
})
export class AppModule {}
